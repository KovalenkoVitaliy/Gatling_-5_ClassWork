Action()
{

	web_url("computers", 
		"URL=http://computer-database.gatling.io/computers", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_url("ASCI White", 
		"URL=http://computer-database.gatling.io/computers/311", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(9);

	web_url("computers_2", 
		"URL=http://computer-database.gatling.io/computers?p=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(4);

	web_url("computers_3", 
		"URL=http://computer-database.gatling.io/computers?p=87", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_header("UA-CPU", 
		"AMD64");

	lr_think_time(4);

	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE11/1478281996/iecompatviewlist.xml", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	web_url("482", 
		"URL=http://computer-database.gatling.io/computers/482", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers?p=87", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("482_2", 
		"Action=http://computer-database.gatling.io/computers/482", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers/482", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=name", "Value=lenovo thinkpad x61sdfsdfsd", ENDITEM, 
		"Name=introduced", "Value=", ENDITEM, 
		"Name=discontinued", "Value=", ENDITEM, 
		"Name=company", "Value=", ENDITEM, 
		LAST);

	return 0;
}