/*!****************************************************************************
 * @file    ap_portal_html.h
 * @brief   HTML content for AP Portal web interface.
 * Embedded HTML/CSS/JavaScript for WiFi configuration.
 * @author  Quattrone Martin
 * @date    Feb 2026
 *******************************************************************************/

#ifndef AP_PORTAL_HTML_H
#define AP_PORTAL_HTML_H

static const char* HTML_PORTAL = R"html(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Guardian - WiFi Setup</title>
    <style>
        :root {
            --bg-color: #1a222c;
            --card-bg: #242c38;
            --text-primary: #ffffff;
            --text-secondary: #a0aabf;
            --input-bg: #151a22;
            --border-color: #333d4b;
            --btn-primary: #0d6efd;
            --btn-hover: #0b5ed7;
            --btn-secondary: #333d4b;
            --success: #198754;
            --error: #dc3545;
        }

        * { margin: 0; padding: 0; box-sizing: border-box; }
        body { font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; background-color: var(--bg-color); color: var(--text-primary); display: flex; align-items: center; justify-content: center; min-height: 100vh; padding: 20px; }
        
        .container { background-color: var(--card-bg); border-radius: 16px; box-shadow: 0 10px 30px rgba(0,0,0,0.5); max-width: 420px; width: 100%; padding: 40px 30px; }
        
        /* Placeholder for your Logo */
        .logo-container { width: 80px; height: 80px; background-color: var(--input-bg); border-radius: 50%; margin: 0 auto 20px auto; display: flex; align-items: center; justify-content: center; border: 2px dashed var(--border-color); }
        .logo-text { font-size: 12px; color: var(--text-secondary); }

        .header { text-align: center; margin-bottom: 25px; }
        .header h1 { font-size: 24px; margin-bottom: 8px; font-weight: 600; }
        .header p { color: var(--text-secondary); font-size: 14px; line-height: 1.5; }
        
        .form-group { margin-bottom: 20px; }
        label { display: block; margin-bottom: 8px; color: var(--text-secondary); font-weight: 500; font-size: 13px; }
        
        input[type="text"], input[type="password"] { width: 100%; padding: 12px 15px; background-color: var(--input-bg); border: 1px solid var(--border-color); border-radius: 8px; color: var(--text-primary); font-size: 15px; transition: border-color 0.3s ease; }
        input:focus { outline: none; border-color: var(--btn-primary); }
        
        .networks-list { max-height: 180px; overflow-y: auto; border: 1px solid var(--border-color); background-color: var(--input-bg); border-radius: 8px; margin-bottom: 20px; }
        .network-item { padding: 12px 15px; border-bottom: 1px solid var(--border-color); cursor: pointer; transition: background 0.2s ease; display: flex; justify-content: space-between; align-items: center; }
        .network-item:hover { background-color: var(--border-color); }
        .network-item.selected { background-color: rgba(13, 110, 253, 0.2); border-left: 3px solid var(--btn-primary); }
        .network-ssid { font-weight: 600; font-size: 14px; margin-bottom: 4px; }
        .network-rssi { font-size: 12px; color: var(--text-secondary); }
        
        button { width: 100%; padding: 14px 20px; background-color: var(--btn-primary); color: white; border: none; border-radius: 8px; font-size: 16px; font-weight: 600; cursor: pointer; transition: background-color 0.2s ease; margin-top: 10px; }
        button:hover { background-color: var(--btn-hover); }
        button:disabled { opacity: 0.7; cursor: not-allowed; }
        
        .button-secondary { background-color: var(--btn-secondary); font-size: 14px; padding: 10px; margin-top: 0; margin-bottom: 10px; }
        .button-secondary:hover { background-color: #434f61; }
        
        .message { padding: 12px; border-radius: 8px; margin-bottom: 20px; font-size: 14px; display: none; text-align: center; }
        .message.show { display: block; }
        .message.success { background-color: rgba(25, 135, 84, 0.2); color: #47b27b; border: 1px solid var(--success); }
        .message.error { background-color: rgba(220, 53, 69, 0.2); color: #ea868f; border: 1px solid var(--error); }
        
        .status { padding: 12px 15px; background-color: var(--input-bg); border-radius: 8px; border-left: 4px solid var(--btn-primary); margin-bottom: 25px; font-size: 14px; }
        .status-connected { border-left-color: var(--success); }
        .status-disconnected { border-left-color: var(--error); }
        
        .loading { display: none; text-align: center; color: var(--text-secondary); font-size: 14px; padding: 20px; }
        .loading.show { display: block; }
    </style>
</head>
<body>
    <div class="container">
        <div class="logo-container">
            <span class="logo-text">LOGO</span>
        </div>

        <div class="header">
            <h1>Guardian Setup</h1>
            <p>Connect your device to the local network</p>
        </div>
        
        <div id="statusContainer" class="status status-disconnected">
            <strong>Status:</strong> <span id="statusText">Waiting for configuration...</span>
        </div>
        
        <div id="wifiMessage" class="message"></div>
        
        <div class="form-group">
            <label>Select your WiFi network:</label>
            <button class="button-secondary" id="scanBtn" onclick="scanNetworks()">🔄 Scan networks</button>
            <div id="loadingWifi" class="loading">Scanning networks... please wait.</div>
            <div id="networksList" class="networks-list" style="display:none;"></div>
        </div>
        
        <div class="form-group">
            <label for="ssid">SSID (Network Name):</label>
            <input type="text" id="ssid" placeholder="Your WiFi network name">
        </div>
        
        <div class="form-group">
            <label for="password">WiFi Password:</label>
            <input type="password" id="password" placeholder="Leave empty if open network">
        </div>
        
        <button id="connectBtn" onclick="saveWifiCredentials()">Save and Connect</button>
    </div>
    
    <script>
        function showMessage(message, type) {
            const msgEl = document.getElementById('wifiMessage');
            msgEl.textContent = message;
            msgEl.className = `message show ${type}`;
            setTimeout(() => msgEl.classList.remove('show'), 5000);
        }
        
        function scanNetworks() {
            const loading = document.getElementById('loadingWifi');
            const list = document.getElementById('networksList');
            const btn = document.getElementById('scanBtn');
            
            loading.classList.add('show');
            list.style.display = 'none';
            btn.disabled = true;
            
            fetch('/api/wifi-networks')
                .then(r => r.json())
                .then(data => {
                    loading.classList.remove('show');
                    btn.disabled = false;
                    
                    if (!data.networks || data.networks.length === 0) {
                        showMessage('No WiFi networks found', 'error');
                        return;
                    }
                    
                    list.innerHTML = '';
                    data.networks.forEach(network => {
                        const item = document.createElement('div');
                        item.className = 'network-item';
                        item.innerHTML = `
                            <div class="network-info">
                                <div class="network-ssid">${escapeHtml(network.ssid)}</div>
                                <div class="network-rssi">${network.rssi} dBm (Ch ${network.channel})</div>
                            </div>
                        `;
                        item.onclick = () => selectNetwork(network.ssid, item);
                        list.appendChild(item);
                    });
                    
                    list.style.display = 'block';
                })
                .catch(err => {
                    loading.classList.remove('show');
                    btn.disabled = false;
                    showMessage('Error scanning networks.', 'error');
                });
        }
        
        function selectNetwork(ssid, element) {
            document.querySelectorAll('.network-item').forEach(item => {
                item.classList.remove('selected');
            });
            element.classList.add('selected');
            document.getElementById('ssid').value = ssid;
        }
        
        function saveWifiCredentials() {
            const ssid = document.getElementById('ssid').value.trim();
            const password = document.getElementById('password').value;
            const btn = document.getElementById('connectBtn');
            
            if (!ssid) {
                showMessage('Please enter the WiFi network name', 'error');
                return;
            }
            
            btn.disabled = true;
            btn.innerText = "Connecting...";

            const payload = { ssid: ssid, password: password };
            
            fetch('/api/credentials', {
                method: 'POST',
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify(payload)
            })
            .then(r => r.json())
            .then(data => {
                if (data.success) {
                    showMessage('Credentials saved! Device is connecting...', 'success');
                    updateStatus();
                } else {
                    showMessage(data.message || 'Unknown error', 'error');
                    btn.disabled = false;
                    btn.innerText = "Save and Connect";
                }
            })
            .catch(err => {
                showMessage('Connection error.', 'error');
                btn.disabled = false;
                btn.innerText = "Save and Connect";
            });
        }
        
        function updateStatus() {
            fetch('/api/status')
                .then(r => r.json())
                .then(data => {
                    const container = document.getElementById('statusContainer');
                    const text = document.getElementById('statusText');
                    
                    if (data.connected) {
                        container.className = 'status status-connected';
                        text.textContent = '✓ Connected to ' + escapeHtml(data.ssid);
                    } else {
                        container.className = 'status status-disconnected';
                        text.textContent = 'Waiting for configuration...';
                    }
                })
                .catch(err => console.error('Error updating status:', err));
        }
        
        function escapeHtml(text) {
            const div = document.createElement('div');
            div.textContent = text;
            return div.innerHTML;
        }
        
        updateStatus();
        setInterval(updateStatus, 5000);
    </script>
</body>
</html>
)html";

#endif // AP_PORTAL_HTML_H