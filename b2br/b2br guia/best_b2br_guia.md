# Walkthrough -- Born2BeRoot
## This is a System Administration related project

#### This tutorial will help you to configure your VM for the BornToBeRoot project

## Settings
### VM Setup
* VirtualBox: New
* Name: Anything you like
* Machine folder: /sgoinfre/Perso/\<yourlogin>
* Type: Linux
* Version: Debian 64-bit
---
1. RAM: 1024MB
2. Create a virtual hard disk now (VDI)
3. Fixed size: 8GB

### Install your Debian


**Power On your VM and select your OS (Debian)**

1. Select Install (Don't select graphical install it is useless)
2. Language: English
3. Choose **your** area
4. Choose United State (en_US.UTF-8) and American English for keyboard
5. Hostname: login+42
6. Domain: *leave empty*

**Now configure your account and root** 

1. Choose a password for root that feat with subject
    * (you can take an easy password but don't forget to change it)
3. Full Name *leave empty*
4. Username: login
5. Choose a password that feat with subject
    * (you can take an easy password but don't forget to change it)

**Now configure your disk**
1. Partition methode: Guided - Use entire disk and set up encrypted LVM
2. **YES**
3. Select *Separate /home partition* (don't forget)
4. Enter strong passphrase
    * (you can change it later but I recommande to make it hard now)
5. **CONTINUE**
6. Select *Finish partioning and write changes to disk*
7. **YES**
8. Package Manager: No
9. Choose your Country and deb.debian.org
10. HTTP Proxy: Leave empty
11. Participate in the package usage survey: **NO**
12. GRUB YES: sda

## Configuration
Power On your VM and login as user: root

### Install libpam and Setup password policy
```
root@login42:~# apt install libpam-pwquality
```
##### Setup password policy

```
root@login42:~# nano /etc/security/pwquality.conf 
```
You need to uncomment these lines and change some values.
```
difok = 7
minlen = 10
dcredit = -1
ucredit = -1
lcredit = -1
maxrepeat = 3
usercheck = 1
enforcing = 1
retry = 3
enforce_for_root
```
---
```
root@login42:~# nano /etc/login.defs
```
Replace these lines
```
PASS_MAX_DAYS    30
PASS_MIN_DAYS    2
```
Before making any other changes, you must run these commands.
```
root@login42:~# chage <yourlogin>
        Minimum Password Age [0]: 2
        Maximum Password Age [9999]: 30
        Last Password Change (YYYY-MM-DD) [date]: <last time you change password>
        Password Expiration Warning [7]: 7
        (Enter for the rest)
                           
root@login42:~# chage root
        Same as before
```

### Install and configure UFW

```
root@login42:~# apt install ufw
root@login42:~# ufw enable
root@login42:~# ufw allow 4242
root@login42:~# ufw status
```
you should have something like this:
![](https://i.imgur.com/2dWpUFK.png)

### Configure SSH

```
root@login42:~# nano /etc/ssh/sshd_config
```
Uncomment and set:
```
Port 4242
PermitRootLogin no
```
---
Uncomment and set:
```
root@login42:~# nano /etc/ssh/ssh_config
```

```
Port 4242
```


### install and Configure Sudo
```
root@login42:~# apt install sudo
```
```
root@login42:~# mkdir /var/log/sudo
root@login42:~# touch /var/log/sudo/sudo.log
root@login42:~# nano /etc/sudoers
```

Setup like this:
```
Defaults    passwd_tries=3
Defaults    badpass_message="<you message when some enter a wrong password>"
Defaults    logfile="/var/log/sudo/sudo.log"
Defaults    log_input,log_output
Defaults    requiretty
Defaults    secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```

### Add Group and setup your user

```
root@login42:~# addgroup user42
root@login42:~# usermod -aG user42 <yourlogin>
root@login42:~# usermod -aG sudo <yourlogin>
```

### Network Configuration

```
root@login42:~# sudo shutdown now
```

1. VirtualBox: settings
2. Network: Adapter 1: Bridged Adapter
3. On your VM

```
root@login42:~# hostname -I
```
4. On host computer
```
ssh <login>@<hostname -I> -p 4242
```
