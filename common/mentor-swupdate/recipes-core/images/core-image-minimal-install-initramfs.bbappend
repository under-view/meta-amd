# The local.conf.append fragments from meta-mentor-swupdate
# add this post-proc command which is not applicable to ramfs
# images so drop it to avoid build failures. 
IMAGE_POSTPROCESS_COMMAND_remove = "swupdate_deploy_description;"
