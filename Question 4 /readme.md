tail -f server.log 2>/dev/null | grep "ERROR" | tee -a error_report.txt
