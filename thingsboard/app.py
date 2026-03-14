from flask import Flask, request, jsonify, render_template
import requests
import configparser
import sys

app = Flask(__name__)

# ==========================================
# 1. CONFIGURATION (LOADED FROM CFG FILE)
# ==========================================
config = configparser.ConfigParser()
if not config.read('framework.cfg'):
    print("[ERROR] Could not read 'framework.cfg'.")
    sys.exit(1)

try:
    TB_URL = config.get('ThingsBoard', 'TB_URL')
    TENANT_EMAIL = config.get('ThingsBoard', 'TENANT_EMAIL')
    TENANT_PASSWORD = config.get('ThingsBoard', 'TENANT_PASSWORD')
    DASHBOARD_ID = config.get('ThingsBoard', 'DASHBOARD_ID')
except configparser.NoOptionError as e:
    print(f"[ERROR] Missing configuration: {e}")
    sys.exit(1)

# ==========================================
# 2. THINGSBOARD API FUNCTIONS
# ==========================================
def get_token():
    url = f"{TB_URL}/api/auth/login"
    response = requests.post(url, json={"username": TENANT_EMAIL, "password": TENANT_PASSWORD})
    response.raise_for_status()
    return response.json().get("token")

def create_customer(token, customer_name):
    url = f"{TB_URL}/api/customer"
    headers = {"X-Authorization": f"Bearer {token}", "Content-Type": "application/json"}
    response = requests.post(url, json={"title": customer_name}, headers=headers)
    response.raise_for_status()
    return response.json().get("id").get("id")

def assign_device_to_customer(token, customer_id, device_id):
    url = f"{TB_URL}/api/customer/{customer_id}/device/{device_id}"
    headers = {"X-Authorization": f"Bearer {token}"}
    response = requests.post(url, headers=headers)
    response.raise_for_status()

def assign_dashboard_to_customer(token, customer_id, dashboard_id):
    url = f"{TB_URL}/api/customer/{customer_id}/dashboard/{dashboard_id}"
    headers = {"X-Authorization": f"Bearer {token}"}
    response = requests.post(url, headers=headers)
    response.raise_for_status()

def create_user(token, customer_id, user_email, dashboard_id):
    url = f"{TB_URL}/api/user?sendActivationMail=true"
    headers = {"X-Authorization": f"Bearer {token}", "Content-Type": "application/json"}
    payload = {
        "email": user_email,
        "authority": "CUSTOMER_USER",
        "customerId": {"entityType": "CUSTOMER", "id": customer_id},
        "additionalInfo": {
            "defaultDashboardId": dashboard_id,
            "defaultDashboardFullscreen": True,
            "homeDashboardId": dashboard_id,
            "homeDashboardHideToolbar": True
        }
    }
    response = requests.post(url, json=payload, headers=headers)
    response.raise_for_status()

# ==========================================
# 3. WEB ROUTES
# ==========================================

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/api/register', methods=['POST'])
def register_device():
    data = request.get_json()
    user_email = data.get('email')
    device_id = data.get('device_id')

    if not user_email or not device_id:
        return jsonify({"error": "Missing email"}), 400

    try:
        print(f"[*] Registering user: {user_email} | Device: {device_id}")
        
        token = get_token()
        customer_id = create_customer(token, f"{user_email}")
        assign_device_to_customer(token, customer_id, device_id)
        assign_dashboard_to_customer(token, customer_id, DASHBOARD_ID)
        create_user(token, customer_id, user_email, DASHBOARD_ID)

        print("[+] Registration completed")
        return jsonify({"message": "Successfull registration"}), 200

    except requests.exceptions.HTTPError as e:
        error_msg = e.response.json().get("message", str(e))
        print(f"[!] Error API: {error_msg}")
        return jsonify({"error": error_msg}), 500
    except Exception as e:
        print(f"[!] Error Server: {str(e)}")
        return jsonify({"error": "Server internal error"}), 500

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)