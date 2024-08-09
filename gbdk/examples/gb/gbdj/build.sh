#the path of gbdj folder
read myPath
path="$myPath/gbdj/"

numTileset="1"
lisTileset="asciiDark"

numTilemap="1"
lisTilemap="mainMenu"

numPreset="1"
lisPreset=""

numSample="8"
lisSample="kick,snare,hat,tom,bass0,bass1,bass2,bass3"

echo "Converting png tilesets into c files:"
python  gbdj/res/tiles/maketileset.py $path $numTileset $lisTileset

echo "Converting txt tilemaps into c files:"
python   gbdj/res/maps/maketilemap.py $path $numTilemap $lisTilemap

echo "Converting txt presets into c files:"
python  gbdj/res/preset/makepreset.py $path $numPreset $lisPreset

echo "Converting wav samples into c files:"
python gbdj/res/samples/makesample.py $path $numSample $lisSample
