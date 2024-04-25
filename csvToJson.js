const fs = require('fs');
const XLSX = require('xlsx');

// Use the correct path to your Excel file
const excelFilePath = '/Users/saraaltarazi/ZakHanafi.github.io/farmersmarket_2024-42505049.xlsx';
const jsonFilePath = '/Users/saraaltarazi/ZakHanafi.github.io/farmersmarket.json';

// Read the Excel file
const workbook = XLSX.readFile(excelFilePath);
const sheetName = workbook.SheetNames[0];
const worksheet = workbook.Sheets[sheetName];
const results = XLSX.utils.sheet_to_json(worksheet);

// Write the JSON file
fs.writeFile(jsonFilePath, JSON.stringify(results, null, 2), (err) => {
  if (err) {
    console.error('An error occurred:', err);
    return;
  }
  console.log(`JSON file was saved to ${jsonFilePath}`);
});
