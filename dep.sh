read -p 'package manager: ' p

sudo $p install gcc
sudo $p install cmake
sudo $p install python
sudo $p install git
sudo $p install pip

pip install wave
pip install pillow
pip install pyboy

latest=4.3.0
wget https://github.com/gbdk-2020/gbdk-2020/releases/download/$latest/gbdk-linux64.tar.gz
tar xzvf gbdk-linux64.tar.gz
mv gbdk gbdk-2020
rm gbdk-linux64.tar.gz
