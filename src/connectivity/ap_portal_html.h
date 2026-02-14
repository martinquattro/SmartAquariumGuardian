/*!****************************************************************************
 * @file    ap_portal_html.h
 * @brief   HTML content for AP Portal web interface.
 *          Embedded HTML/CSS/JavaScript for WiFi and MQTT configuration.
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
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }
        
        body {
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, sans-serif;
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            min-height: 100vh;
            display: flex;
            align-items: center;
            justify-content: center;
            padding: 20px;
        }
        
        .container {
            background: white;
            border-radius: 10px;
            box-shadow: 0 10px 40px rgba(0,0,0,0.2);
            max-width: 500px;
            width: 100%;
            padding: 30px;
        }
        
        .header {
            text-align: center;
            margin-bottom: 30px;
        }
        
        .header h1 {
            color: #333;
            font-size: 24px;
            margin-bottom: 5px;
        }
        
        .header p {
            color: #666;
            font-size: 14px;
        }
        
        .tabs {
            display: flex;
            border-bottom: 2px solid #e0e0e0;
            margin-bottom: 30px;
        }
        
        .tab-button {
            flex: 1;
            padding: 15px;
            background: none;
            border: none;
            border-bottom: 3px solid transparent;
            cursor: pointer;
            font-size: 14px;
            font-weight: 600;
            color: #999;
            transition: all 0.3s ease;
        }
        
        .tab-button.active {
            color: #667eea;
            border-bottom-color: #667eea;
        }
        
        .tab-button:hover {
            color: #667eea;
        }
        
        .tab-content {
            display: none;
        }
        
        .tab-content.active {
            display: block;
        }
        
        .form-group {
            margin-bottom: 20px;
        }
        
        label {
            display: block;
            margin-bottom: 8px;
            color: #333;
            font-weight: 600;
            font-size: 14px;
        }
        
        input[type="text"],
        input[type="password"],
        input[type="number"],
        select {
            width: 100%;
            padding: 12px;
            border: 1px solid #ddd;
            border-radius: 5px;
            font-size: 14px;
            font-family: inherit;
            transition: border-color 0.3s ease;
        }
        
        input[type="text"]:focus,
        input[type="password"]:focus,
        input[type="number"]:focus,
        select:focus {
            outline: none;
            border-color: #667eea;
            box-shadow: 0 0 0 3px rgba(102, 126, 234, 0.1);
        }
        
        .networks-list {
            max-height: 200px;
            overflow-y: auto;
            border: 1px solid #ddd;
            border-radius: 5px;
            margin-bottom: 20px;
        }
        
        .network-item {
            padding: 12px;
            border-bottom: 1px solid #eee;
            cursor: pointer;
            transition: background 0.2s ease;
            display: flex;
            justify-content: space-between;
            align-items: center;
        }
        
        .network-item:hover {
            background: #f5f5f5;
        }
        
        .network-item.selected {
            background: #e8eef7;
        }
        
        .network-info {
            flex: 1;
        }
        
        .network-ssid {
            font-weight: 600;
            color: #333;
            margin-bottom: 4px;
        }
        
        .network-rssi {
            font-size: 12px;
            color: #999;
        }
        
        .signal-strength {
            display: inline-block;
            width: 20px;
            height: 12px;
            background: linear-gradient(90deg, #667eea 0%, #667eea var(--strength), #ddd var(--strength), #ddd 100%);
            border-radius: 2px;
        }
        
        button {
            width: 100%;
            padding: 12px;
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            color: white;
            border: none;
            border-radius: 5px;
            font-size: 16px;
            font-weight: 600;
            cursor: pointer;
            transition: transform 0.2s ease, box-shadow 0.2s ease;
        }
        
        button:hover {
            transform: translateY(-2px);
            box-shadow: 0 5px 15px rgba(102, 126, 234, 0.4);
        }
        
        button:active {
            transform: translateY(0);
        }
        
        .button-secondary {
            background: #f0f0f0;
            color: #333;
            margin-top: 10px;
            font-size: 14px;
        }
        
        .button-secondary:hover {
            background: #e0e0e0;
            box-shadow: none;
        }
        
        .loading {
            display: none;
            text-align: center;
            color: #667eea;
            font-size: 14px;
            padding: 20px;
        }
        
        .loading.show {
            display: block;
        }
        
        .spinner {
            display: inline-block;
            width: 16px;
            height: 16px;
            border: 2px solid #ddd;
            border-top-color: #667eea;
            border-radius: 50%;
            animation: spin 0.8s linear infinite;
            margin-right: 8px;
        }
        
        @keyframes spin {
            to { transform: rotate(360deg); }
        }
        
        .message {
            padding: 12px;
            border-radius: 5px;
            margin-bottom: 20px;
            font-size: 14px;
            display: none;
        }
        
        .message.show {
            display: block;
        }
        
        .message.success {
            background: #d4edda;
            color: #155724;
            border: 1px solid #c3e6cb;
        }
        
        .message.error {
            background: #f8d7da;
            color: #721c24;
            border: 1px solid #f5c6cb;
        }
        
        .status {
            padding: 15px;
            background: #f9f9f9;
            border-radius: 5px;
            border-left: 4px solid #667eea;
            margin-bottom: 20px;
            font-size: 14px;
        }
        
        .status-connected {
            border-left-color: #28a745;
            background: #f0f9f7;
        }
        
        .status-disconnected {
            border-left-color: #dc3545;
            background: #fdf8f8;
        }
        
        .help-text {
            font-size: 12px;
            color: #999;
            margin-top: 5px;
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>Guardian</h1>
            <p>Configure your Smart Aquarium</p>
        </div>
        
        <div id="statusContainer" class="status status-disconnected">
            <strong>Status:</strong> <span id="statusText">Waiting for configuration...</span>
        </div>
        
        <div class="tabs">
            <button class="tab-button active" onclick="switchTab('wifi')">WiFi</button>
            <button class="tab-button" onclick="switchTab('mqtt')">MQTT</button>
        </div>
        
        <div id="wifi" class="tab-content active">
            <div id="wifiMessage" class="message"></div>
            
            <div class="form-group">
                <label>Select your WiFi network:</label>
                <button class="button-secondary" onclick="scanNetworks()">🔄 Scan networks</button>
                <div id="loadingWifi" class="loading">
                    <span class="spinner"></span>Scanning networks...
                </div>
                <div id="networksList" class="networks-list" style="display:none;"></div>
            </div>
            
            <div class="form-group">
                <label for="ssid">SSID or network name:</label>
                <input type="text" id="ssid" placeholder="Your WiFi network name">
                <div class="help-text">Enter manually if your network doesn't appear</div>
            </div>
            
            <div class="form-group">
                <label for="password">WiFi Password:</label>
                <input type="password" id="password" placeholder="Your network password">
            </div>
            
            <button onclick="saveWifiCredentials()">Save and Connect</button>
        </div>
        
        <div id="mqtt" class="tab-content">
            <div id="mqttMessage" class="message"></div>
            
            <div class="form-group">
                <label for="broker">MQTT Broker Address:</label>
                <input type="text" id="broker" placeholder="mqtt.example.com or 192.168.1.100">
                <div class="help-text">Optional - configure later if preferred</div>
            </div>
            
            <div class="form-group">
                <label for="port">MQTT Port:</label>
                <input type="number" id="port" placeholder="1883" value="1883" min="1" max="65535">
            </div>
            
            <div class="form-group">
                <label for="username">Username (optional):</label>
                <input type="text" id="username" placeholder="Broker username">
            </div>
            
            <div class="form-group">
                <label for="mqttPassword">Password (optional):</label>
                <input type="password" id="mqttPassword" placeholder="Broker password">
            </div>
            
            <button onclick="saveMqttCredentials()">Save MQTT Configuration</button>
        </div>
    </div>
    
    <script>
        function switchTab(tabName) {
            const tabs = document.querySelectorAll('.tab-content');
            const buttons = document.querySelectorAll('.tab-button');
            
            tabs.forEach(tab => tab.classList.remove('active'));
            buttons.forEach(btn => btn.classList.remove('active'));
            
            document.getElementById(tabName).classList.add('active');
            event.target.classList.add('active');
        }
        
        function showMessage(elementId, message, type) {
            const msgEl = document.getElementById(elementId);
            msgEl.textContent = message;
            msgEl.className = `message show ${type}`;
            setTimeout(() => msgEl.classList.remove('show'), 5000);
        }
        
        function scanNetworks() {
            const loading = document.getElementById('loadingWifi');
            const list = document.getElementById('networksList');
            
            loading.classList.add('show');
            list.style.display = 'none';
            
            fetch('/api/wifi-networks')
                .then(r => r.json())
                .then(data => {
                    loading.classList.remove('show');
                    
                    if (!data.networks || data.networks.length === 0) {
                        showMessage('wifiMessage', 'No WiFi networks found', 'error');
                        return;
                    }
                    
                    list.innerHTML = '';
                    data.networks.forEach(network => {
                        const strength = Math.max(20, Math.min(100, network.rssi + 100)) + '%';
                        const item = document.createElement('div');
                        item.className = 'network-item';
                        item.innerHTML = `
                            <div class="network-info">
                                <div class="network-ssid">${escapeHtml(network.ssid)}</div>
                                <div class="network-rssi">
                                    <span class="signal-strength" style="--strength: ${strength}"></span>
                                    ${network.rssi} dBm - Channel ${network.channel}
                                </div>
                            </div>
                        `;
                        item.onclick = () => selectNetwork(network.ssid, item);
                        list.appendChild(item);
                    });
                    
                    list.style.display = 'block';
                })
                .catch(err => {
                    loading.classList.remove('show');
                    showMessage('wifiMessage', 'Error scanning networks: ' + err.message, 'error');
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
            
            if (!ssid) {
                showMessage('wifiMessage', 'Please enter the WiFi network name', 'error');
                return;
            }
            
            if (!password) {
                showMessage('wifiMessage', 'Please enter the WiFi password', 'error');
                return;
            }
            
            const payload = {
                ssid: ssid,
                password: password
            };
            
            fetch('/api/credentials', {
                method: 'POST',
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify(payload)
            })
                .then(r => r.json())
                .then(data => {
                    if (data.success) {
                        showMessage('wifiMessage', 'Credentials saved. Connecting...', 'success');
                        updateStatus();
                    } else {
                        showMessage('wifiMessage', data.message || 'Unknown error', 'error');
                    }
                })
                .catch(err => showMessage('wifiMessage', 'Error: ' + err.message, 'error'));
        }
        
        function saveMqttCredentials() {
            const broker = document.getElementById('broker').value.trim();
            const port = parseInt(document.getElementById('port').value) || 1883;
            const username = document.getElementById('username').value.trim();
            const password = document.getElementById('mqttPassword').value;
            
            if (!broker) {
                showMessage('mqttMessage', 'Please enter the MQTT broker address', 'error');
                return;
            }
            
            const payload = {
                broker: broker,
                port: port,
                username: username,
                password: password
            };
            
            fetch('/api/mqtt-credentials', {
                method: 'POST',
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify(payload)
            })
                .then(r => r.json())
                .then(data => {
                    if (data.success) {
                        showMessage('mqttMessage', 'MQTT configuration saved', 'success');
                    } else {
                        showMessage('mqttMessage', data.message || 'Unknown error', 'error');
                    }
                })
                .catch(err => showMessage('mqttMessage', 'Error: ' + err.message, 'error'));
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
        
        // Update status on load and periodically
        updateStatus();
        setInterval(updateStatus, 5000);
    </script>
</body>
</html>
)html";

#endif // AP_PORTAL_HTML_H