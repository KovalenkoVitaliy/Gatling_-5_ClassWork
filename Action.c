Action()
{
	
	int i;
	char* s;
	int currentpage;
	
		web_reg_save_param_ex(
		"ParamName=CompId",
		"LB=<td><a href=\"/computers/",
		"RB=\">",
		"Ordinal=10",
		SEARCH_FILTERS,
		LAST);
	
		web_url("computers", 
		"URL=http://computer-database.gatling.io/computers", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
		web_reg_save_param_regexp(
		"ParamName=NameComp1",
		"RegExp=\"name\" value=\"(.*)\"",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);
	
		web_url("ASCI White", 
		"URL=http://computer-database.gatling.io/computers/{CompId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	while ( i == 0) {
	
		lr_save_int(currentpage, "CurrentPage");	
		
		web_reg_find("Text=Nothing to display",
		"SaveCount=Count",	             
		LAST);
	
		web_url("computers_3", 
		"URL=http://computer-database.gatling.io/computers?p={CurrentPage}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
		
		s = lr_eval_string("{Count}");
		i = atoi(s);
		lr_output_message("Chislo povtoreniy: %s",lr_eval_string("{Count}"));
	
		if ( i == 1) {
		
		currentpage = currentpage - 1;
		lr_save_int(currentpage, "LastPage");
		lr_output_message("LastPage: %s",lr_eval_string("{LastPage}"));
		
		web_reg_save_param_ex(
		"ParamName=CompIdLast",
		"LB=<td><a href=\"/computers/",
		"RB=\">",
		"Ordinal=last",
		SEARCH_FILTERS,
		LAST);
		
		web_url("computers_3", 
		"URL=http://computer-database.gatling.io/computers?p={LastPage}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
		
		web_submit_data("482_2", 
		"Action=http://computer-database.gatling.io/computers/{CompIdLast}", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers/{CompIdLast}", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=name", "Value={NameComp1}", ENDITEM, 
		"Name=introduced", "Value=", ENDITEM, 
		"Name=discontinued", "Value=", ENDITEM, 
		"Name=company", "Value=", ENDITEM, 
		LAST);

		}
		
		currentpage = currentpage + 1;

	}
	
		lr_output_message("ID last computer: %s",lr_eval_string("{CompIdLast}"));
		lr_output_message("Name last computer: %s",lr_eval_string("{NameComp1}"));
	
	return 0;
}