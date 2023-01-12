
const { query } = require('express');
const express = require('express');
const query_model = require('../models/query');

const showform =(req,res)=>{
     res.render('index');
    // res.render('query');
}

const recomended_data = async(req,res)=>{

  //  query_model.create(req.body);
  //  res.send("created");
  const queryobject={};

    const {soil_type,Nitrogen_level,phosphorous_level,potassium_level,humidity_level,choice,month} = req.body;
    

   const data = await query_model.find({soil_type,Nitrogen_level,phosphorous_level,potassium_level,humidity_level,choice,month});
     const x = await data;
    //  console.log(x);
     res.render('recommend',{x});
    

  
}
const showarticle = async(req,res)=>{

  res.render('crop_article');

}

module.exports = {showform,recomended_data,showarticle};