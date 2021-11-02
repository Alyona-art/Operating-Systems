sudo echo Alyona > lofsdisk/file1.txt
sudo echo Artemeva > lofsdisk/file2.txt
sudo cp ex2.c lofsdisk
sudo gcc lofsdisk/ex2.c -o lofsdisk/ex2.out
gcc ex2.c -o ex2.out

sudo mkdir lofsdisk/bin
fi
sudo cp /bin/bash lofsdisk/bin
sudo cp /bin/ls lofsdisk/bin
sudo cp /bin/cat lofsdisk/bin
sudo cp /bin/echo lofsdisk/bin

sudo mkdir lofsdisk/lib
sudo mkdir lofsdisk/lib64
sudo mkdir lofsdisk/lib/x86_64-linux-gnu
fi
sudo cp /lib/x86_64-linux-gnu/libtinfo.so.6 $FSDISK/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libc.so.6 $FSDISK/lib/x86_64-linux-gnu
sudo cp /lib64/ld-linux-x86-64.so.2 $FSDISK/lib64
sudo cp /lib/x86_64-linux-gnu/libselinux.so.1 $FSDISK/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libpcre2-8.so.0 $FSDISK/lib/x86_64-linux-gnu

sudo chroot lofsdisk ./ex2.out > ex2.txt
./ex2.out >> ex2.txt