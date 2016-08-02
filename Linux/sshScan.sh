#!/bin/bash
myvar=100
while [ $myvar -le 255 ]
do
        cmd="root@192.168.1.""$myvar"
        echo $cmd
        ssh $cmd
        myvar=$(( $myvar + 1 ))
done
 