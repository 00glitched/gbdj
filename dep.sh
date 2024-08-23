read -p 'package manager: ' p

sudo $p install gcc
sudo $p install cmake
sudo $p install python
sudo $p install git
sudo $p install pip

pip install wave
pip install pillow
pip install pyboy

git clone https://github.com/gbdk-2020/gbdk-2020.git
cd gbdk-2020
make