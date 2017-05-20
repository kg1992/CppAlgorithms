function DoChapter1()
{
    make 1
    
    echo == Program1.1 ==================================================================
    ./bin/Program1.1 10 < ./in/1.connectivity.txt
    echo == Program1.2 ==================================================================
    ./bin/Program1.2 10 < ./in/1.connectivity.txt
    echo == Program1.3 ==================================================================
    ./bin/Program1.3 10 < ./in/1.connectivity.txt
    echo == Program1.4 ==================================================================
    ./bin/Program1.4 10 < ./in/1.connectivity.txt
    echo == Exercise1.16 ================================================================
    ./bin/Exercise1.16 10 < ./in/1.connectivity.txt
}

function DoChapter2()
{
    make 2
    
    echo == Program2.1 ==================================================================
    ./bin/Program2.1
}

if [ "$1" == "1" ]
then
    DoChapter1
elif [ "$1" == "2" ]
then
    DoChapter2
fi