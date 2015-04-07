MOZ_LIBDIR=/usr/lib/firefox
MOZ_APP_LAUNCHER=`which $0`
MOZ_APP_NAME=firefox
MOZ_DEFAULT_PROFILEDIR=.mozilla/firefox
MOZ_PROFILEDIR=.mozilla/firefox
export MOZ_APP_LAUNCHER
while [ ! -x $MOZ_LIBDIR/$MOZ_APP_NAME ] ; do
if [ -L "$MOZ_APP_LAUNCHER" ] ; then
MOZ_APP_LAUNCHER=`readlink -f $MOZ_APP_LAUNCHER`
MOZ_LIBDIR=`dirname $MOZ_APP_LAUNCHER`
else
echo "Can't find $MOZ_LIBDIR/$MOZ_APP_NAME"
exit 1
done
usage () {
MOZ_LIBDIR/$MOZ_APP_NAME -h | sed -e 's,/.*/,,'
echo
moz_debug=0
moz_debugger_args=""
moz_debugger="gdb"
while [ $# -gt 0 ]; do
case "$1" in
usage
exit 0
moz_debug=1
shift
moz_debugger=$2;
if [ "${moz_debugger}" != "" ]; then
shift 2
else
echo "-d requires an argument"
exit 1
moz_debugger_args=$2;
if [ "${moz_debugger_args}" != "" ] ; then
shift 2
else
echo "-a requires an argument"
exit 1
shift
break
break
esac
done
if [ $moz_debug -eq 1 ] ; then
case $moz_debugger in
debugger="valgrind"
debugger=$moz_debugger
esac
debugger=`which $debugger`
if [ ! -x $debugger ] ; then
echo "Invalid debugger"
exit 1
case `basename $moz_debugger` in
gdb)
exec $debugger $moz_debugger_args --args $MOZ_LIBDIR/$MOZ_APP_NAME "$@"
echo "$MOZ_APP_NAME has not been compiled with valgrind support"
exit 1
exec $debugger $moz_debugger_args $MOZ_LIBDIR/$MOZ_APP_NAME "$@"
else
exec $MOZ_LIBDIR/$MOZ_APP_NAME "$@"
