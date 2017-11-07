/*Demo program for orphan process*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    pid_t pid;
    pid=fork();
    
    if(pid==0)
    {
        sleep(5);
        printf("Child Process\n");
        printf("ppid=%ld\n",(long)getppid());
    }
    else
    {
        printf("Parent\n");
    }
    return 0;
}




/*
exam@c05l0322-HP-EliteDesk-800-G1-TWR:~$ cd Desktop
exam@c05l0322-HP-EliteDesk-800-G1-TWR:~/Desktop$ gcc orphan.c
exam@c05l0322-HP-EliteDesk-800-G1-TWR:~/Desktop$ ./a.out
Parent
exam@c05l0322-HP-EliteDesk-800-G1-TWR:~/Desktop$ Child Process
ppid=1999
ps -axu
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root         1  0.1  0.0  33904  3224 ?        Ss   15:47   0:00 /sbin/init
root         2  0.0  0.0      0     0 ?        S    15:47   0:00 [kthreadd]
root         3  0.0  0.0      0     0 ?        S    15:47   0:00 [ksoftirqd/0]
root         4  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/0:0]
root         5  0.0  0.0      0     0 ?        S<   15:47   0:00 [kworker/0:0H]
root         7  0.0  0.0      0     0 ?        S    15:47   0:00 [rcu_sched]
root         8  0.0  0.0      0     0 ?        S    15:47   0:00 [rcuos/0]
root         9  0.0  0.0      0     0 ?        S    15:47   0:00 [rcuos/1]
root        10  0.0  0.0      0     0 ?        S    15:47   0:00 [rcuos/2]
root        11  0.0  0.0      0     0 ?        S    15:47   0:00 [rcuos/3]
root        12  0.0  0.0      0     0 ?        S    15:47   0:00 [rcuos/4]
root        13  0.0  0.0      0     0 ?        S    15:47   0:00 [rcuos/5]
root        14  0.0  0.0      0     0 ?        S    15:47   0:00 [rcuos/6]
root        15  0.0  0.0      0     0 ?        S    15:47   0:00 [rcuos/7]
root        16  0.0  0.0      0     0 ?        S    15:47   0:00 [rcu_bh]
root        17  0.0  0.0      0     0 ?        S    15:47   0:00 [rcuob/0]
root        18  0.0  0.0      0     0 ?        S    15:47   0:00 [rcuob/1]
root        19  0.0  0.0      0     0 ?        S    15:47   0:00 [rcuob/2]
root        20  0.0  0.0      0     0 ?        S    15:47   0:00 [rcuob/3]
root        21  0.0  0.0      0     0 ?        S    15:47   0:00 [rcuob/4]
root        22  0.0  0.0      0     0 ?        S    15:47   0:00 [rcuob/5]
root        23  0.0  0.0      0     0 ?        S    15:47   0:00 [rcuob/6]
root        24  0.0  0.0      0     0 ?        S    15:47   0:00 [rcuob/7]
root        25  0.0  0.0      0     0 ?        S    15:47   0:00 [migration/0]
root        26  0.0  0.0      0     0 ?        S    15:47   0:00 [watchdog/0]
root        27  0.0  0.0      0     0 ?        S    15:47   0:00 [watchdog/1]
root        28  0.0  0.0      0     0 ?        S    15:47   0:00 [migration/1]
root        29  0.0  0.0      0     0 ?        S    15:47   0:00 [ksoftirqd/1]
root        30  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/1:0]
root        31  0.0  0.0      0     0 ?        S<   15:47   0:00 [kworker/1:0H]
root        32  0.0  0.0      0     0 ?        S    15:47   0:00 [watchdog/2]
root        33  0.0  0.0      0     0 ?        S    15:47   0:00 [migration/2]
root        34  0.0  0.0      0     0 ?        S    15:47   0:00 [ksoftirqd/2]
root        35  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/2:0]
root        36  0.0  0.0      0     0 ?        S<   15:47   0:00 [kworker/2:0H]
root        37  0.0  0.0      0     0 ?        S    15:47   0:00 [watchdog/3]
root        38  0.0  0.0      0     0 ?        S    15:47   0:00 [migration/3]
root        39  0.0  0.0      0     0 ?        S    15:47   0:00 [ksoftirqd/3]
root        41  0.0  0.0      0     0 ?        S<   15:47   0:00 [kworker/3:0H]
root        42  0.0  0.0      0     0 ?        S    15:47   0:00 [watchdog/4]
root        43  0.0  0.0      0     0 ?        S    15:47   0:00 [migration/4]
root        44  0.0  0.0      0     0 ?        S    15:47   0:00 [ksoftirqd/4]
root        45  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/4:0]
root        46  0.0  0.0      0     0 ?        S<   15:47   0:00 [kworker/4:0H]
root        47  0.0  0.0      0     0 ?        S    15:47   0:00 [watchdog/5]
root        48  0.0  0.0      0     0 ?        S    15:47   0:00 [migration/5]
root        49  0.0  0.0      0     0 ?        S    15:47   0:00 [ksoftirqd/5]
root        50  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/5:0]
root        51  0.0  0.0      0     0 ?        S<   15:47   0:00 [kworker/5:0H]
root        52  0.0  0.0      0     0 ?        S    15:47   0:00 [watchdog/6]
root        53  0.0  0.0      0     0 ?        S    15:47   0:00 [migration/6]
root        54  0.0  0.0      0     0 ?        S    15:47   0:00 [ksoftirqd/6]
root        56  0.0  0.0      0     0 ?        S<   15:47   0:00 [kworker/6:0H]
root        57  0.0  0.0      0     0 ?        S    15:47   0:00 [watchdog/7]
root        58  0.0  0.0      0     0 ?        S    15:47   0:00 [migration/7]
root        59  0.0  0.0      0     0 ?        S    15:47   0:00 [ksoftirqd/7]
root        60  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/7:0]
root        61  0.0  0.0      0     0 ?        S<   15:47   0:00 [kworker/7:0H]
root        62  0.0  0.0      0     0 ?        S<   15:47   0:00 [khelper]
root        63  0.0  0.0      0     0 ?        S    15:47   0:00 [kdevtmpfs]
root        64  0.0  0.0      0     0 ?        S<   15:47   0:00 [netns]
root        65  0.0  0.0      0     0 ?        S<   15:47   0:00 [writeback]
root        66  0.0  0.0      0     0 ?        S<   15:47   0:00 [kintegrityd]
root        67  0.0  0.0      0     0 ?        S<   15:47   0:00 [bioset]
root        68  0.0  0.0      0     0 ?        S<   15:47   0:00 [kworker/u17:0]
root        69  0.0  0.0      0     0 ?        S<   15:47   0:00 [kblockd]
root        70  0.0  0.0      0     0 ?        S<   15:47   0:00 [ata_sff]
root        71  0.0  0.0      0     0 ?        S    15:47   0:00 [khubd]
root        72  0.0  0.0      0     0 ?        S<   15:47   0:00 [md]
root        73  0.0  0.0      0     0 ?        S<   15:47   0:00 [devfreq_wq]
root        74  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/2:1]
root        76  0.0  0.0      0     0 ?        S    15:47   0:00 [khungtaskd]
root        77  0.0  0.0      0     0 ?        S    15:47   0:00 [kswapd0]
root        78  0.0  0.0      0     0 ?        SN   15:47   0:00 [ksmd]
root        79  0.0  0.0      0     0 ?        SN   15:47   0:00 [khugepaged]
root        80  0.0  0.0      0     0 ?        S    15:47   0:00 [fsnotify_mark]
root        81  0.0  0.0      0     0 ?        S    15:47   0:00 [ecryptfs-kthre
root        82  0.0  0.0      0     0 ?        S<   15:47   0:00 [crypto]
root        94  0.0  0.0      0     0 ?        S<   15:47   0:00 [kthrotld]
root        95  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/u16:1]
root        96  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/6:1]
root        97  0.0  0.0      0     0 ?        S    15:47   0:00 [scsi_eh_0]
root        98  0.0  0.0      0     0 ?        S    15:47   0:00 [scsi_eh_1]
root        99  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/u16:2]
root       100  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/0:1]
root       120  0.0  0.0      0     0 ?        S<   15:47   0:00 [deferwq]
root       121  0.0  0.0      0     0 ?        S<   15:47   0:00 [charger_manage
root       122  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/6:2]
root       123  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/3:1]
root       124  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/1:1]
root       128  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/4:1]
root       135  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/7:1]
root       136  0.0  0.0      0     0 ?        S    15:47   0:00 [kworker/5:1]
root       197  0.0  0.0      0     0 ?        S    15:47   0:00 [jbd2/sda10-8]
root       198  0.0  0.0      0     0 ?        S<   15:47   0:00 [ext4-rsv-conve
root       322  0.0  0.0  19600   944 ?        S    15:48   0:00 upstart-udev-br
root       327  0.0  0.0  51708  1964 ?        Ss   15:48   0:00 /lib/systemd/sy
root       389  0.0  0.0      0     0 ?        S    15:48   0:00 [irq/42-mei_me]
root       414  0.0  0.0      0     0 ?        S<   15:48   0:00 [kpsmoused]
root       415  0.0  0.0      0     0 ?        S<   15:48   0:00 [hd-audio1]
root       462  0.0  0.0      0     0 ?        S    15:48   0:00 [kworker/3:2]
root       527  0.0  0.0  15260   632 ?        S    15:48   0:00 upstart-socket-
root       583  0.0  0.0      0     0 ?        S<   15:48   0:00 [hd-audio0]
root       588  0.0  0.0  23424   848 ?        Ss   15:48   0:00 rpcbind
root       618  0.0  0.0      0     0 ?        S<   15:48   0:00 [kworker/u17:1]
root       643  0.0  0.0      0     0 ?        S    15:48   0:00 [jbd2/sda8-8]
root       644  0.0  0.0      0     0 ?        S<   15:48   0:00 [ext4-rsv-conve
message+   735  0.0  0.0  40280  2512 ?        Ss   15:48   0:00 dbus-daemon --s
root       765  0.0  0.1 330256  4924 ?        Ssl  15:48   0:00 /usr/sbin/Modem
root       767  0.0  0.0  19292  1492 ?        Ss   15:48   0:00 /usr/sbin/bluet
root       781  0.0  0.0      0     0 ?        S<   15:48   0:00 [krfcommd]
root       787  0.0  0.0  15408   692 ?        S    15:48   0:00 upstart-file-br
syslog     840  0.0  0.0 255840  1872 ?        Ssl  15:48   0:00 rsyslogd
avahi      865  0.0  0.0  32348  1652 ?        S    15:48   0:00 avahi-daemon: r
root       871  0.0  0.0  43560  1936 ?        Ss   15:48   0:00 /lib/systemd/sy
avahi      876  0.0  0.0  32224   464 ?        S    15:48   0:00 avahi-daemon: c
root       921  0.0  0.0  20016   964 tty4     Ss+  15:48   0:00 /sbin/getty -8 
root       925  0.0  0.0  20016   964 tty5     Ss+  15:48   0:00 /sbin/getty -8 
root       932  0.0  0.0  20016   956 tty2     Ss+  15:48   0:00 /sbin/getty -8 
root       933  0.0  0.0  20016   964 tty3     Ss+  15:48   0:00 /sbin/getty -8 
root       937  0.0  0.0  20016   952 tty6     Ss+  15:48   0:00 /sbin/getty -8 
root       966  0.0  0.0  61372  3048 ?        Ss   15:48   0:00 /usr/sbin/sshd 
root       985  0.0  0.0  23532  1328 ?        Ss   15:48   0:00 /usr/sbin/vsftp
root      1010  0.0  0.0  23656  1032 ?        Ss   15:48   0:00 cron
root      1011  0.0  0.0   4368   712 ?        Ss   15:48   0:00 acpid -c /etc/a
root      1012  0.0  0.0  75352  3400 ?        Ss   15:48   0:00 /usr/sbin/cups-
kernoops  1024  0.0  0.0  37144  1012 ?        Ss   15:48   0:00 /usr/sbin/kerne
root      1044  0.0  0.1 292636  4548 ?        SLsl 15:48   0:00 lightdm
mysql     1055  0.1  1.3 558216 51032 ?        Ssl  15:48   0:00 /usr/sbin/mysql
root      1062  0.0  0.0  19188   744 ?        Ss   15:48   0:00 /usr/sbin/irqba
root      1098  0.5  3.4 2995708 129552 ?      Sl   15:48   0:03 /usr/bin/java -
root      1104  0.7  2.2 515860 84980 tty7     Ssl+ 15:48   0:06 /usr/bin/X -cor
root      1121  0.0  0.1 302220  5044 ?        Sl   15:48   0:00 /usr/lib/accoun
root      1133  0.0  0.2 356568  8816 ?        Ssl  15:48   0:00 NetworkManager
root      1144  0.0  0.1 295864  5920 ?        Sl   15:48   0:00 /usr/lib/policy
whoopsie  1197  0.0  0.1 363460  5336 ?        Ssl  15:48   0:00 whoopsie
root      1259  0.0  0.0      0     0 ?        S    15:48   0:00 [kauditd]
root      1279  0.0  0.3 188628 14112 ?        Ss   15:48   0:00 /usr/sbin/apach
www-data  1292  0.0  0.1 188652  5412 ?        S    15:48   0:00 /usr/sbin/apach
www-data  1293  0.0  0.1 188652  5412 ?        S    15:48   0:00 /usr/sbin/apach
www-data  1294  0.0  0.1 188652  5412 ?        S    15:48   0:00 /usr/sbin/apach
www-data  1295  0.0  0.1 188652  5412 ?        S    15:48   0:00 /usr/sbin/apach
www-data  1296  0.0  0.1 188652  5412 ?        S    15:48   0:00 /usr/sbin/apach
root      1329  0.0  0.0  20016   960 tty1     Ss+  15:48   0:00 /sbin/getty -8 
root      1383  0.0  0.0  10232  3716 ?        S    15:48   0:00 /sbin/dhclient 
root      1480  0.0  0.1 170480  3780 ?        Sl   15:48   0:00 lightdm --sessi
root      1549  0.0  0.1 239364  4536 ?        Sl   15:48   0:00 /usr/lib/upower
rtkit     1594  0.0  0.0 168916  1312 ?        SNl  15:48   0:00 /usr/lib/rtkit/
nobody    1826  0.0  0.0  35224  1540 ?        S    15:48   0:00 /usr/sbin/dnsma
exam      1997  0.0  0.1 249008  4984 ?        Sl   15:48   0:00 /usr/bin/gnome-
exam      1999  0.0  0.0  40188  2568 ?        Ss   15:48   0:00 init --user
exam      2069  0.0  0.0  10616   316 ?        Ss   15:48   0:00 ssh-agent -s
exam      2072  0.0  0.0  41268  2604 ?        Ss   15:48   0:00 dbus-daemon --f
exam      2081  0.0  0.0  22300  1152 ?        Ss   15:48   0:00 upstart-event-b
exam      2085  0.0  0.1  78200  4356 ?        Ss   15:48   0:00 /usr/lib/x86_64
exam      2098  0.0  0.0  30784   452 ?        S    15:48   0:00 upstart-file-br
exam      2099  0.1  0.1 450348  5168 ?        Ssl  15:48   0:00 /usr/bin/ibus-d
exam      2113  0.0  0.0  22308   396 ?        S    15:48   0:00 upstart-dbus-br
exam      2114  0.0  0.0  22308   396 ?        S    15:48   0:00 upstart-dbus-br
exam      2117  0.0  0.4 823152 18700 ?        Ssl  15:48   0:00 /usr/lib/unity-
exam      2121  0.0  0.6 714204 22868 ?        Ssl  15:48   0:00 /usr/lib/x86_64
exam      2123  0.0  0.1 367676  6664 ?        Ssl  15:48   0:00 /usr/lib/at-spi
exam      2124  0.0  0.3 584972 13884 ?        Ssl  15:48   0:00 gnome-session -
exam      2126  0.0  0.4 507332 18472 ?        Ssl  15:48   0:00 /usr/lib/unity/
exam      2130  0.0  0.0  39360  2048 ?        S    15:48   0:00 /bin/dbus-daemo
exam      2134  0.0  0.0 124912  3312 ?        Sl   15:48   0:00 /usr/lib/at-spi
exam      2146  0.0  0.0 196640  3164 ?        Sl   15:48   0:00 /usr/lib/gvfs/g
exam      2150  0.0  0.1 360424  3916 ?        Sl   15:48   0:00 /usr/lib/gvfs/g
exam      2170  0.0  0.3 559064 14480 ?        Sl   15:48   0:00 /usr/lib/x86_64
exam      2172  0.0  0.1 295768  4288 ?        Sl   15:48   0:00 /usr/lib/ibus/i
exam      2174  0.0  0.4 489072 17692 ?        Sl   15:48   0:00 /usr/lib/ibus/i
exam      2181  0.0  0.2 396400  8100 ?        Sl   15:48   0:00 /usr/lib/ibus/i
exam      2202  0.0  0.1 219912  4124 ?        Sl   15:48   0:00 /usr/lib/ibus/i
colord    2211  0.0  0.1 311024  6360 ?        Sl   15:48   0:00 /usr/lib/colord
exam      2213  0.0  0.4 662164 15604 ?        Sl   15:48   0:00 /usr/lib/x86_64
exam      2220  0.0  0.1 365176  4032 ?        Ssl  15:48   0:00 /usr/lib/x86_64
exam      2221  0.0  0.1 293756  4052 ?        Ssl  15:48   0:00 /usr/lib/x86_64
exam      2223  0.0  0.1 295636  4368 ?        Ssl  15:48   0:00 /usr/lib/x86_64
exam      2225  0.0  0.2 1164576 9036 ?        Ssl  15:48   0:00 /usr/lib/x86_64
exam      2231  0.0  0.2 495592  8524 ?        Ssl  15:48   0:00 /usr/lib/x86_64
exam      2232  0.0  0.3 456024 11820 ?        Ssl  15:48   0:00 /usr/lib/x86_64
exam      2244  0.0  0.1 447592  6212 ?        S<l  15:48   0:00 /usr/bin/pulsea
exam      2246  0.0  0.1 906384  4688 ?        Ssl  15:48   0:00 /usr/lib/x86_64
exam      2247  0.0  0.1 286748  5024 ?        Ssl  15:48   0:00 /usr/lib/x86_64
exam      2293  0.0  0.2 492588 11156 ?        Sl   15:48   0:00 /usr/lib/evolut
exam      2304  0.0  0.2 349844 10648 ?        Sl   15:48   0:00 /usr/lib/x86_64
exam      2310  0.0  0.0 178304  2696 ?        Sl   15:48   0:00 /usr/lib/dconf/
exam      2434  0.7  1.8 1280096 68572 ?       Sl   15:48   0:05 compiz
exam      2446  0.0  1.2 1097012 45480 ?       Sl   15:48   0:00 /usr/lib/evolut
exam      2448  0.0  0.2 341192 10196 ?        Sl   15:48   0:00 /usr/lib/policy
exam      2451  0.0  0.4 602616 18460 ?        Sl   15:48   0:00 nm-applet
exam      2452  0.0  0.3 410640 12244 ?        Sl   15:48   0:00 /usr/lib/unity-
exam      2457  0.1  0.8 1097012 32284 ?       Sl   15:48   0:00 nautilus -n
exam      2465  0.0  0.0  58152  3664 ?        S    15:48   0:00 /usr/lib/x86_64
exam      2470  0.0  0.1 311436  5920 ?        Sl   15:48   0:00 /usr/lib/gvfs/g
root      2483  0.0  0.1 386256  6132 ?        Sl   15:48   0:00 /usr/lib/udisks
exam      2493  0.0  0.0 200272  2816 ?        Sl   15:48   0:00 /usr/lib/gvfs/g
exam      2497  0.0  0.0 212436  3376 ?        Sl   15:48   0:00 /usr/lib/gvfs/g
exam      2501  0.0  0.0 285960  3356 ?        Sl   15:48   0:00 /usr/lib/gvfs/g
exam      2520  0.0  0.1 270376  5104 ?        Sl   15:48   0:00 /usr/lib/gvfs/g
exam      2526  0.0  0.1 447900  4440 ?        Sl   15:48   0:00 /usr/lib/gvfs/g
exam      2545  0.0  0.0 124516  2812 ?        Sl   15:48   0:00 /usr/lib/gvfs/g
root      2555  0.0  0.1  76852  3780 ?        Ss   15:48   0:00 /usr/sbin/cupsd
exam      2602  0.0  0.3 457268 12232 ?        Sl   15:48   0:00 telepathy-indic
exam      2608  0.0  0.2 336560  8148 ?        Sl   15:48   0:00 /usr/lib/telepa
exam      2621  0.0  0.2 454428  9880 ?        Sl   15:48   0:00 zeitgeist-datah
exam      2626  0.0  0.1 363632  5472 ?        Sl   15:48   0:00 /usr/bin/zeitge
exam      2632  0.0  0.2 256392  9672 ?        Sl   15:48   0:00 /usr/lib/x86_64
exam      2656  0.0  0.0  11412   360 ?        S    15:48   0:00 /bin/cat
exam      2684  0.0  0.3 507520 14072 ?        Sl   15:49   0:00 update-notifier
exam      2706  0.6  3.0 668312 114452 ?       SNl  15:49   0:04 /usr/bin/python
exam      2731  0.0  0.1 385264  4688 ?        Sl   15:50   0:00 /usr/lib/x86_64
exam      2783  9.1  9.5 1119320 355904 ?      Sl   15:56   0:25 /usr/lib/firefo
exam      2811  0.0  0.1 287216  3944 ?        Sl   15:56   0:00 /usr/lib/libuni
root      2881  0.0  0.0      0     0 ?        S    15:57   0:00 [kworker/u16:0]
exam      2884  1.5  1.1 922720 43896 ?        Sl   15:57   0:02 gedit
exam      2982  1.0  0.7 353684 27224 ?        Sl   15:58   0:01 /usr/bin/python
root      3122  0.0  0.0  17516  1116 ?        S    15:58   0:00 /lib/systemd/sy
exam      3137  0.5  0.5 658276 19088 ?        Sl   15:59   0:00 gnome-terminal
exam      3146  0.0  0.0  14824   800 ?        S    15:59   0:00 gnome-pty-helpe
exam      3147  0.0  0.1  27048  4012 pts/0    Ss   15:59   0:00 bash
exam      3206  0.0  0.0  22644  1308 pts/0    R+   16:00   0:00 ps -axu

*/
