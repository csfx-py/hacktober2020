#!/bin/sh
#put your all ip and port in ip.txt file and it will give you the results. 
#ex:- 
#ip1 port
#ip2 port
#ip3 port

file=ip.txt
while read line
do
  ip=$( echo "$line" |cut -d ' '  -f 1 )
  port=$( echo "$line" |cut -d ' '  -f 2 )
  if  timeout 5 telnet  $ip $port </dev/null 2>&1 | grep -q Escape
  then
    echo "$ip $port Connected" >> Telnet_Success.txt
  elif  timeout 5 telnet  $ip $port </dev/null 2>&1 | grep -q refused
  then
    echo "$ip $port Refused" >> Telnet_Refused.txt
  else
    echo "$ip $port Failed" >> Telnet_Failure.txt
  fi
done < ${file}
