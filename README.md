## useful commands 

``grep -c "error" /var/log/dpkg.log ``
`` grep -c -v "error" /var/log/dpkg.log ``
ignore the case -i

## sed stream editor
### substitute
#### s/search/replace/g
#### s/search/replace/l
``sed 's/bash/bashscripting/g' dummy.txt``
``sed -i 's/bash/bashscripting/g' dummy.txt``

### awk
``awk '{print $1 $3}' table.txt ``
#### -F for deleimiter 
``awk -F '{print $1 $3}' table.txt``

### word count 
``ls -l /etc/*conf | wc ``  
     35     295    2000

``ps -ef``