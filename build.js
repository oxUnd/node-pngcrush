var fs = require('fs');

var content = fs.readFileSync('./ChangeLog', {
	encoding: 'utf-8'
});

var vars = content.match(/(.+?),\s*Version(.+?)\n/g);
for (var v in vars) {
	var res = vars[v].match(/.+?,\s*Version\s*(\d+\.\d+\.\d+)(.*?)/);
	if (!res) {
		continue;
	}
	var version = res[1].trim();
	if (parseFloat((version.split('.'))[1]) >= 8) {
		console.log(version);
	}
}

