echo ""
echo "list of png files: "
find "./tiles" -name *.png
#name=$(find "./tiles" -name *.png) 
echo ""
echo "name of png file to convert:"
read name
echo ""
./GameBoyPngConverter "./tiles/$name.png" -a
echo "list of c files: "
find "./tiles" -name *.c
echo ""