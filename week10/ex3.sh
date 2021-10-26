echo Alyona Art. > _ex3.txt
chmod a-x _ex3.txt
stat -c "%a %n" _ex3.txt > ex3.txt
chmod uo+rwx _ex3.txt
stat -c "%a %n" _ex3.txt >> ex3.txt
chmod -R g=u _ex3.txt
stat -c "%a %n" _ex3.txt >> ex3.txt
