#!/bin/bash

TOKEN="1456475406:AAElnAwRKIYGPhh5tFBgA0ZGkHQrP_YEiDs"
ID="1498658345"
MENSAJE="WARNING!! Possible intrusió."
URL="https://api.telegram.org/bot$TOKEN/sendMessage"

curl -s -X POST $URL -d chat_id=$ID -d text="$MENSAJE"


