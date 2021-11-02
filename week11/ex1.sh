sudo fallocate -l 50M lofs.img
sudo losetup -f lofs.img
sudo mkfs.ext4 losetup -a | grep lofs.img | awk '{print substr($1, 1, lenght($1)-1)}'
mkdir lofsdisk
sudo mount losetup -a | grep lofs.img | awk '{print substr($1, 1, lenght($1)-1)}' lofsdisk
