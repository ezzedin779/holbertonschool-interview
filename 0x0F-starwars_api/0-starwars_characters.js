#!/usr/bin/node
const request = require('request');
const process = require('process');
const Id = process.argv[2];
const characters = [];
request({ url: (`https://swapi-api.hbtn.io/api/films/${Id}/`), json: true }, function (e, res, json) {
	if (e) {
		return console.log(e);
	}
	for (const i of json.characters) {
		request({ url: i, json: true }, function (err, res, json) {
			if (err) {
				return console.log(err);
			}
			const id = i.split('/')[5];
			characters[id] = json.name;
		}, 2000);
	}
	setTimeout(function () {
		json.characters.forEach(element => {
			const id = element.split('/')[5];
			console.log(characters[id]);
		});
	}, 2000);
});
