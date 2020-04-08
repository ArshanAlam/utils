# Access Point

I wrote this bash script for creating an access point, on my laptop, using a working ethernet based internet connection.


**NOTE:** Some wireless interfaces do not have *AP* (Access Point) functionality

This script has only been testing on Arch Linux


You will need:
- A wireless interface
- Working ethernet-based internet connection
- Name of you wireless interface and ethernet interface
- dhcpcd DHCP/DHCPv6 client
  - Your DHCP client must be configured (see below)


Please refer to Arch Linux Wiki on [software access points](https://wiki.archlinux.org/index.php/software_access_point#Wi-Fi_link_layer)


Example DHCP configurations `/etc/hostapd/hostapd.conf`
~~~
ssid=YourWiFiName
wpa_passphrase=Somepassphrase
interface=wlan0_ap
bridge=br0
auth_algs=3
channel=7
driver=nl80211
hw_mode=g
logger_stdout=-1
logger_stdout_level=2
max_num_sta=5
rsn_pairwise=CCMP
wpa=2
wpa_key_mgmt=WPA-PSK
wpa_pairwise=TKIP CCMP
~~~

### Usage

To start, stop, and restart the access point, use the following syntax

`accessPoint <WIRELESS_INTERFACE> <ETHERNET_INTERFACE> start|stop|restart`


**Example:** Start access point

`accessPoint wlan0 enp0s12 start`
