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

`"ip range"` = `any`, `CIDR notation of IP address`

Examples:

`any`, `!any`

`192.168.0.0/24`, `!192.168.0.0/24`, `[192.168.0.0/24,10.0.0.0/24]`, `![192.168.0.0/24,10.0.0.0/24]`, ...

`$HOME_NET`, `$EXTERNAL_NET`, `!$HOME_NET`, `!$EXTERNAL_NET`, ...

___

`"port"` = port number

Examples:

`any` = any port

`1:1024` = ports ranging from 1 to 1024

`:6000` = ports less than or equal to 6000

`500:` = ports greater than or equal to 500

The `!` operator can be used to negate ports.

___

`"direction operator"` = `->`, `<>`

from `->` to

`<>` = in both directions

___
