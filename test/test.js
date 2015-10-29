var C = require('..');
var fs = require('fs');
var path = require('path');


fs.readFile(path.join(__dirname, './alphatest.png'), function (err, data) {
  if (err) throw err;
  
  var buffer = C.compress(data);

  fs.writeFile(path.join(__dirname, './alphatest_out.png'), buffer, {
      flags: 'wb'
  }, function(err){});
  
});

