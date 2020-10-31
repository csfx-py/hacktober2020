#!/bin/bash

#This script runs AWS DMS Task using aws-cli2
#To use this script aws-cli 2 should be installed in your system
#Add this sctip to cron for automation.

export AWS_DEFAULT_REGION=us-east-1 #change this
export AWS_DEFAULT_OUTPUT=json #change this
export AWS_ACCESS_KEY_ID=****************LEJA #change this
export AWS_SECRET_ACCESS_KEY=****************qvNn #change this
/usr/local/bin/aws dms start-replication-task --replication-task-arn task-arn --start-replication-task-type reload-target 
