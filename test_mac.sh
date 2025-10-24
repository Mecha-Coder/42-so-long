#!/bin/bash

# Function to run a test case
run_test() {
    local description="$1"
    local command="$2"
    local argument="$3"

    echo -e "\n--> $description\n"
    echo -e "$argument\n"
    output=$($command 2>&1)
    echo "$output"

    # Run valgrind to check for memory leaks
    leak_output=$(leaks --atExit -- $command > /dev/null 2>&1)
    if [ $? -eq 0 ]; then
        echo -e "$(tput setaf 2)OK$(tput sgr0)\n================================================\n" 
    else
        echo -e "$(tput setaf 1)KO$(tput sgr0)\n================================================\n"
        echo "$leak_output"
    fi
}

echo -e "WRONG INPUT TEST\n==============\n"

run_test "No argument" "./so_long" ""
run_test "Multiple arguments" "./so_long dsadsa dsad" "dsadsa dsad"
run_test "Multiple .ber arguments" "./so_long dsa.ber dsa.ber dsa.ber dsa.ber" "dsa.ber dsa.ber dsa.ber dsa.ber"

echo -e "\n--> Not .ber extension\n"
run_test "Invalid extension 1" "./so_long d,ber" "d,ber"
run_test "Invalid extension 2" "./so_long error.error" "error.error"
run_test "Invalid extension 3" "./so_long .be" ".be"
run_test "Invalid extension 4" "./so_long d.txt" "d.txt"
run_test "Invalid extension 5" "./so_long dsadadasdber" "dsadadasdber"
run_test "Invalid extension 6" "./so_long asd.ber12" "asd.ber12"

echo -e "DOWNLOAD MAP\n==============\n"

run_test "No file 1" "./so_long .ber" ".ber"
run_test "No file 2" "./so_long dsadadasd.ber" "dsadadasd.ber"
run_test "No file 3" "./so_long a.ber" "a.ber"
run_test "No file 4" "./so_long ./dsad./dsa.ber" "./dsad./dsa.ber"
run_test "No file 5" "./so_long test.ber" "test.ber"

echo -e "\n--> Invalid map\n"
run_test "Invalid map 1" "./so_long ./maps/error/.ber" "./maps/error/.ber"
run_test "Invalid map 2" "./so_long ./maps/error/error1.ber" "./maps/error/error1.ber"
run_test "Invalid map 3" "./so_long ./maps/error/error2.ber" "./maps/error/error2.ber"
run_test "Invalid map 4" "./so_long ./maps/error/error3.ber" "./maps/error/error3.ber"
run_test "Invalid map 5" "./so_long ./maps/error/error4.ber" "./maps/error/error4.ber"
run_test "Invalid map 6" "./so_long ./maps/error/error5.ber" "./maps/error/error5.ber"
run_test "Invalid map 7" "./so_long ./maps/error/error6.ber" "./maps/error/error6.ber"
run_test "Invalid map 8" "./so_long ./maps/error/error7.ber" "./maps/error/error7.ber"
run_test "Invalid map 9" "./so_long ./maps/error/error8.ber" "./maps/error/error8.ber"
run_test "Invalid map 10" "./so_long ./maps/error/error9.ber" "./maps/error/error9.ber"
run_test "Invalid map 11" "./so_long ./maps/error/error10.ber" "./maps/error/error10.ber"
run_test "Invalid map 12" "./so_long ./maps/error/error11.ber" "./maps/error/error11.ber"
run_test "Invalid map 13" "./so_long ./maps/error/error12.ber" "./maps/error/error12.ber"
run_test "Invalid map 14" "./so_long ./maps/error/error13.ber" "./maps/error/error13.ber"
run_test "Invalid map 15" "./so_long ./maps/error/error14.ber" "./maps/error/error14.ber"
run_test "Invalid map 16" "./so_long ./maps/error/error15.ber" "./maps/error/error15.ber"
run_test "Invalid map 17" "./so_long ./maps/error/error16.ber" "./maps/error/error16.ber"
run_test "Invalid map 18" "./so_long ./maps/error/error17.ber" "./maps/error/error17.ber"
run_test "Invalid map 19" "./so_long ./maps/error/error18.ber" "./maps/error/error18.ber"

echo "\n--> Valid map\n"
run_test "Valid map bonus" "./so_long ./maps/bonus/map_bonus.ber" "./maps/bonus/map_bonus.ber"