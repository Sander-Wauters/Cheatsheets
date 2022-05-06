# Commands
## Windows

Open **cmd** and navigate to the where the **snort.exe** file is stored.<br>
The default file location is **C:\Snort\bin**.

___

`"interface number"` = List available interfaces: `snort -W`

`"path to snort.conf"` = **..\Snort\etc\snort.conf**

___

Get list of args: `snort -h`

Listen on selected interface: `snort -i "interface number"`

Test config file: `snort -i "interface number" -c "path to snort.conf" -T`
