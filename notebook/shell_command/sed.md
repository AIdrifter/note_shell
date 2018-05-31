# sed 
sed -i 's/MY_TA_TASK_NAME/EXAMPLE_TASK/g' E*

# ignore postfix string
COMMIT_ID=$(git rev-parse HEAD)
sed -i "s/BUILDHASH:.*/BUILDHASH:${COMMIT_ID:0:7}/g" version_info
BUILD_TIME=$(date +%Y%m%d%H)
sed -i "s/BUILDDATE:.*/BUILDDATE:${BUILD_TIME}/g" version_info

