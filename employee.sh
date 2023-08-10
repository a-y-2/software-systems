#!/usr/bin/bash

#display menu
function display_menu(){
	echo "MENU"
	echo "================================="
	echo "1.create employee record"
	echo "2.delete employee record"
	echo "3.search employee record"
	echo "4.display employee details"
	echo "5.sort"
	echo "6.list all employee records"
	echo "7.exit"
}

#create record
function create(){
	read -p "enter employee name: " name
	read -p "enter employee number: " id
	read -p "enter age: " age
#check if employee already exists
	if grep -q "^.*:$id:.*$" employee_records.txt; then
		echo "employee $id already exists"
	else
		echo "$name|$id|$age" >> employee_records.txt
		echo "record inserted successfully!"
	fi
}

#delete record
function delete(){
	read -p "enter the id of employee to be deleted: " id
	grep -v "^.*:$id:.*$" employee_records.txt > temp.txt
	mv temp.txt employee_records.txt
	echo "deleted successfully!"
}

#search records
function search(){
	read -p "enter the employee number whose record you want: " id
	grep "^.*:$id:.*$" employee_records.txt
}

#display
function display(){
	search
}

#sort records
function sort_records(){
	sort -k2n employee_records.txt
	echo "sorted successfully!"
}

#list all records
function list(){
	while read p
	do
		echo $p
	done < employee_records.txt
}

while true; 
do
	display_menu
	read -p "enter your choice(1-7)  " choice

	case $choice in
		1)
			create
			;;
		2)
			delete
			;;
		3)
			search
			;;
		4)
			display
			;;
		5)
			sort_records
			;;
		6)
			list
			;;
		7)
			exit 0
			;;
		*)
			echo "please enter a valid choice!"
			;;
	esac
done
