mkdir -p ./lib/thirdparty/
find ./lib/ -iwholename "*lib*lib*.h"| xargs -I % sh -c "export name='basename %'; cp % ./lib/thirdparty/$name"
find ./lib/ -iwholename "*lib*lib*.cpp"| xargs -I % sh -c "basename %"