const express = require('express');
const mongoose = require('mongoose');

const connectDB =(uri)=>{
    mongoose.set('strictQuery', true);
mongoose.connect(uri,{
   useNewUrlParser:true,
   useUnifiedTopology:true
});
console.log("database connected");
}




module.exports = connectDB;