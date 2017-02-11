## IEEE-2017

The repository for the SD Mines Robotics Team IEEE Region 5 Robotics Competition robot code.

We are using Git Flow to manage our branches. Period. There will be no debates. Here's how you use it.

* You will need to install Git Flow with `sudo apt install git-flow`
* You will need to clone the [IEEE-2017](https://github.com/sdsmt-robotics/IEEE-2017) repository with `git clone git@github.com:sdsmt-robotics/IEEE-2017.git`. I highly recommend using SSH keys with GitHub. It's pretty easy and it will save you from typing in your password 50 bazillion times.
* You will need to then initialize git flow after cloning the repository with `git flow init`
    * Leave every option as the default except the name of the develop branch. We are using `dev` for the name of our develop branch.
    * If you are beginning work on a new feature, do `git flow feature start <feature name>`. This is based off of the `dev` branch.
    * You can publish your feature for others to collaborate on with `git flow feature publish <feature name>`
    * You can collaborate on an existing feature with `git flow feature pull <feature name>`
* If you are done with a feature, finish it with `git flow feature finish <feature name>`. This will merge the feature branch into `dev` and remove the feature branch.

## Additional notes:
* We are not using other aspects of Git Flow – only the features.
* Note the only changes you should make is to the `dev` branch. Period. Pushes are disabled on `master`. Continuous Integration will handle merging changes into `master` upon the passing of unit tests.
* You can view the branch you're on with `git branch`
* You can change branches with `git checkout`
* Please use good commit messages. I had a potential employer look through last years project and he was not impressed.
