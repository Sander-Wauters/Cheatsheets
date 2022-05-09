# Rules

`"action" "protocol" "ip range" "port" "direction operator" "ip range" "port" "rule option"`

Example: `alert icmp any any -> any any (msg:"Testing ICMP alert"; sid:1000001;)`

___

`"action"` = `alert`, `log`, `pass`, `drop`, `reject`, `sdrop`

`alert` = generate an alert using the selected alert method, and then log the packet

`log` = log the packet

`pass` = ignore the packet

If running Snort in inline mode these additional options are available.<br>
Snort runs in inline mode by default.

`drop` =  block and log the packet

`reject` =  block the packet, log it, and then send a TCP reset if the protocol is TCP or an ICMP port unreachable
message if the protocol is UDP.

`sdrop`= block the packet but do not log it.

___

`"protocol"` = `tcp`, `udp`, `icmp`, `ip`

___
