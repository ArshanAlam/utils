# Ethernet Connection

This script is designed for Linux users that cannot automatically connect to a LAN when an ethernet is connected to their machine.

Executing `./ethernetConnection` will display **usage** information regarding the script.

In your terminal, execute `ip link` to display all network interfaces recognized by your machine.

Identify the ethernet interface, as that will be the name that will replace `[interface]` in the command below:

To use the script you may specify a command and an interface to which you would like to connect `./ethernetConnection <command> [interface]`


**Example with interface name:**
`./ethernetConnection start eth1`
`./ethernetConnection stop eth1`
`./ethernetConnection restart eth1`

**Example without interface name:**
`./ethernetConnection start`
`./ethernetConnection stop`
`./ethernetConnection restart`
