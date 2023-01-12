const express = require('express');
const router = express.Router();

const {showform,recomended_data,showarticle} = require('../controllers/query');


router.route("/").get(showform);

router.route("/").post(recomended_data);
router.route("/crop_article").get(showarticle);


module.exports = router;