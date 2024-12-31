#!/bin/bash

#set -ex

echo "...Checking kaspaz.conf"

if [ ! -e "$HOME/.kaspaz/kaspaz.conf" ]; then
    mkdir -p $HOME/.kaspaz

    echo "...Creating kaspaz.conf"
    cat <<EOF > $HOME/.kaspaz/kaspaz.conf
rpcuser=${rpcuser:-kaspazrpc}
rpcpassword=${rpcpassword:-`dd if=/dev/urandom bs=33 count=1 2>/dev/null | base64`}
txindex=1
bind=${listenip:-127.0.0.1}
rpcbind=${listenip:-127.0.0.1}
EOF

    cat $HOME/.kaspaz/kaspaz.conf
fi

echo "...Checking fetch-params"
$HOME/zcutil/fetch-params.sh
echo "Initialization completed successfully"
echo

# ToDo: Needs some rework. I was sick
if [ $# -gt 0 ]; then

    args=("$@")

elif [  -z ${assetchain+x} ]; then

    args=("-gen -genproclimit=${genproclimit:-2} -pubkey=${pubkey}")

else

    args=("-pubkey=${pubkey} -ac_name=${assetchain} -addnode=${seednode}")

fi

echo
echo "****************************************************"
echo "Running: kaspazd ${args[@]}"
echo "****************************************************"

exec kaspazd ${args[@]}
