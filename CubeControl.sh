while [ 2 > 1 ]
do
TODAY=$(date +"%A")
hour=$(date +"%H")
min=$(date +"%M")
SATERDAY="Saturday"
SUNDAY="Sunday"
if [[ $TODAY == $SATERDAY ]] || [[  $TODAY == $SUNDAY ]]
then
echo "This is a weekend"

if [[ $hour == 07 ]]
then
if [[ $min == 15 ]]
then
curl 192.168.1.142/?twoon

curl 192.168.1.142/?oneon

fi
fi



else
echo "This is not a weekend"
if [[ $hour == 06 ]]
then
if [[ $min == 15 ]]
then
curl 192.168.1.142/?twoon

curl 192.168.1.142/?oneon

fi
fi


echo "Time"
echo $hour
echo $min


if [[ $hour == 21 ]]
then
if [[ $min == 15 ]]
then
curl 192.168.1.142/?off
fi
fi

sleep 60s
done
