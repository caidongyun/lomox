<?php
	
	$dbinfo = require( 'dbconfig.php' );
	
	//ÅäÖÆ Êý¾Ý¿â
	$conn = @mysql_connect('localhost' , $dbinfo['user'] , $dbinfo['password']);
	mysql_select_db( $dbinfo['dbname'] , $conn );
	
	mysql_query('set names \'utf8\'');