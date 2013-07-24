wget  --no-check-certificate https://raw.github.com/joyent/node/v0.10.13/ChangeLog -O ./ChangeLog

vars=$(node build.js)
is_test=$1
echo $is_test

for vv in $vars; do
    if [ "$is_test" != "test" ]; then
        if [ ! -e "./lib/darwin/$vv/png_compress.node" ]; then
            mkdir -p ./lib/darwin/$vv
            node-gyp rebuild --target=$vv
            mv ./build/Release/png_compress.node ./lib/darwin/$vv/png_compress.node
        fi
    else
        echo 'test'
    fi
done
