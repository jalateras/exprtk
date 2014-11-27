/**
 * @author       Jim Alateras
 */
var expect  = require('chai').expect;
var Formula = require('../index');

describe('test exprtk module', function() {
  it('should correctly evaluate the expression 1+1', function() {
    expect(Formula.evaluate("1+1")).to.equal(2);
  });
});
