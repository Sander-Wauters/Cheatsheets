# Users and groups
For more information follow each command with `-h`

## Users
Adding users: `adduser`

Modify users: `usermod`

Deleting users: `delusers` `userdel`

User account information file: `/etc/passwd`

User password information file: `/etc/shadow`


## Groups
Adding groups: `addgroup`

Deleting groups: `delgroup` `groupdel`

Adding users to group: `usermod -aG groupname username`

Delete users from group: `gpasswd -d username groupname`

Group informaion file: `/etc/group`

Group password informaion file: `/etc/gshadow`
