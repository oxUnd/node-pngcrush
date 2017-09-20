var _handle = require('./scripts/util/binding.js')();

function PngCompress(buffer) {
    this._option = '';
    this._callback = function() {};
}

PngCompress.prototype = {
    option: function (opt) {
        if (opt.params) {
            opt = opt.filename ? opt.params + ' ' + opt.filename : opt.params;
        } else {
            opt = opt.filename || '';
        }
        this._option = opt;
        return this;
    },
    compress: function(buffer, cb) {
        if (cb) this._callback = cb;
        if (process.versions.node >= '4.0.0') {
            out = new _handle(buffer, this._option).compress();
        } else {
            out = (new _handle.PngCompress()).compress(buffer, this._option, this._callback);
        }
        return out;
    }
};

module.exports = new PngCompress;
