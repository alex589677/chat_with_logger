#pragma once

void createTableUsers(MYSQL mysql_obj) {
	int qstate = 0;
	std::string temp("CREATE TABLE IF NOT EXISTS users (id INTEGER AUTO_INCREMENT PRIMARY KEY, name VARCHAR(20) NOT NULL);");
	qstate = mysql_query(&mysql_obj, temp.c_str());
	if (qstate == 0) {
		std::cout << "Created table users..." << std::endl;
	}
	else {
		std::cout << "Failed creating table users..." << std::endl;
	}
}

void insertToTableUsers(MYSQL mysql_obj, std::string& str) {
	int qstate = 0;
	std::string temp("INSERT users (name) VALUES ('" + str + "');");
	qstate = mysql_query(&mysql_obj, temp.c_str());
	if (qstate == 0) {
		std::cout << "Record data ..." << std::endl;
	}
	else {
		std::cout << "Failed to insert..." << std::endl;
	}
}

void createTableMessages(MYSQL mysql_obj) {
	int qstate = 0;
	std::string temp("CREATE TABLE IF NOT EXISTS msg (id INTEGER AUTO_INCREMENT PRIMARY KEY, message VARCHAR(20) NOT NULL, user_to VARCHAR(10) NOT NULL);");
	qstate = mysql_query(&mysql_obj, temp.c_str());
	if (qstate == 0) {
		std::cout << "Created table msg..." << std::endl;
	}
	else {
		std::cout << "Failed creating table msg..." << std::endl;
	}
}

void insertToTableMsg(MYSQL mysql_obj, std::string& temp_msg, std::string& to) {
	int qstate = 0;
	std::string temp("INSERT msg (message, user_to) VALUES ('" + temp_msg + "', '" + to + "'); ");
	qstate = mysql_query(&mysql_obj, temp.c_str());
	if (qstate == 0) {
		std::cout << "Record data ..." << std::endl;
	}
	else {
		std::cout << "Failed to insert..." << std::endl;
	}
}