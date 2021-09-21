if test ! -f file
then
    echo 1 > file
fi
if ln file file.lock
        then 
        counter=1
	while [ $counter -le 10 ]
	do
		LastNum=`tail -1 file`
		LastNum=$((LastNum + 1))
		counter=$(expr $counter + 1)
		echo $LastNum >> file
	done
	rm file.lock
fi
