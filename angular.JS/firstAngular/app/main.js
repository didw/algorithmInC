(function () {
    'use strict';

    angular
        .module('foodApp')
        .controller('Main', main);

    function main() {
        var vm = this;
        vm.food = 'Chinese food';
    }
})();