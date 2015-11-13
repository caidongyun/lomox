<?php
	header('Content-type: text/html; charset=utf-8');
	error_reporting(E_ERROR | E_WARNING | E_PARSE);		// 禁止警告 、 捕获运行错误 
	session_start();
	
	require_once( 'db.php' );
	
	$method = trim( $_GET['method'] );
	$action = trim( $_GET['action'] );
	
	controller( $method );
	
	function controller( $method ){
		if( !$method ){ 
			header( 'location:index.html' );
		}
	
		switch( $method ){
			case 'db':
				db( );
				break;
			
			case 'session':
				sessiond( );
				break;
			
			case 'cookie':
				cookied( );
				break;
				
			case 'file':
				filed( );
				break;
	}
	}
	
	//数据库 测试 程序 
	function db( ){
		if( $_GET['action'] == 'clear' ){
			mysql_query('Truncate Table member');
			header( 'location:index.php?method=db' );
			exit;
		}
	
		if( !$_POST ){
			$error = trim( $_GET['error'] );
			$datas = selectAll( );
			include 'db_exam.html';
		
		} else {
			$post = $_POST;
			$info['name'] =trim( $post['name'] );
			$info['sex'] = trim( $post['sex'] );
			
			if( !$info['name'] || !$info['name'] ){
				header( 'location:index.php?method=db&error='.'请输入姓名 和 性别!' );
				exit();
			}
			
			$sql = "INSERT INTO `member` (`id`, `name`, `sex`) VALUES (NULL, '{$info[name]}', '{$info[sex]}');";
			$query =mysql_query( $sql );
			
			header( 'location:index.php?method=db' );
			
		}
	}

	
	//查询所有数据
	function selectAll( ){
		$sql = 'select * from member order by id desc';
		$query =mysql_query( $sql );
		
		$ret =array( );
		while( $row =mysql_fetch_array($query) ){
			$ret[ ] = array( 'name'=>$row['name'] , 'sex'=>$row["sex"] ) ;
		}
		
		return $ret;
	}
	
	//session
	function sessiond( ){
		if( $_GET['action'] =='clear' ){
			$_SESSION['count'] =0;
			header( 'location:index.php?method=session' );
			exit;
		}
	
		$count = (int)$_SESSION["count"];
		
		if( !$count ){
			$count = $_SESSION['count'] =0;
		}
		
		$count++;
		
		$_SESSION[ 'count' ] = $count;
		
		include 'session.html';
	}
	
	//cookie
	function cookied( ){
		if( $_GET['action'] =='clear' ){
			setcookie( 'count' , 0 );
			header( 'location:index.php?method=cookie' );
			exit;
		}
		
		$count = (int)$_COOKIE["count"];
		
		if( !$count ){
			$count =0;
			setcookie( 'count' , 0);
		}
		
		$count++;
		
		setcookie( 'count' , $count );
		
		include 'cookie.html';
	
	}
	
	function filed( ){
		if( $_GET['action'] =='clear' ){
			file_put_contents( 'file_cache.php' , '<?php return '.var_export( array() ,true ).';'  );
			header( 'location:index.php?method=file' );
			exit;
		}
		$info = include 'file_cache.php';
		
		$info[ ] ='第'.(count($info)+1).'个元素!';
		
		file_put_contents( 'file_cache.php' , '<?php return '.var_export( $info ,true ).';'  );
		
		include 'file.html';
	
	}