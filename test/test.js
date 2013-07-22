var C = require('..');
var fs = require('fs');


fs.readFile('./alphatest.png', function (err, data) {
  if (err) throw err;
  var buffer = C.option('-v -bit_depth 8').compress(data);
  fs.writeFile('./alphatest_out.png', buffer, {
      flags: 'wb'
  }, function(err){});
});

