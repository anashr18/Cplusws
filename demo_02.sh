#!/bin/bash

# df -h > disk.txt
# DATE=`date +'%d'`
# echo "$DATE"

# if [ $((DATE % 2)) -eq 0 ]
# then
# echo " 'Even day!' "
# fi

# Hour=$(date +%H | sed 's/^0*//')
# echo " "Current hour is $Hour" "
# if ((Hour % 2 == 0)); then
#     echo "Even hour!"
# else
#     echo "Odd hour!"
# fi

# echo "Enter number"
# read number
# # number=110
# if [ $number -gt 100 ]; then
#     echo " "Number is greater than 100" "
# else
#     echo "Number is less than or equal to 100"
# fi

# divNum=22
# if ((divNum % 10 == 0)); then
#     echo "div by 10!"
# else
#     echo "Not div by 10!"
# fi
user="admin"
if [[ $user=="fdfd" ]]; then
    echo "Admin user!"
else
    echo "Non admin!"
fi