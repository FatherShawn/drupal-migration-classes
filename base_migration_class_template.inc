<?php
/**
 * @file
 * Short file summary goes here
 * 
 * Longer file description goes here
 * Author: Shawn P. Duncan
 * Date: 6/25/14
 * Time: 2:19 PM
 * 
 */


/**
 * Accomplishes what purpose?$
 *
 * Additional description or info goes here 
 * @todo Complete this docBlock
 * @todo Add this file to the files[] listing in .info
 */
abstract class base_migration_class_template extends Migration {
  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments);
    // List the team members...
    $this->team = array(
      new MigrateTeamMember('Name', 'first.last@blinkreaction.com',
                            t('Program Manager')),
      new MigrateTeamMember('Name', 'first.last@blinkreaction.com',
                            t('Dev Lead')),
      new MigrateTeamMember('Your Name', 'first.last@blinkreaction.com',
                            t('Developer')),
    );

    // Define the URL pattern here in the shared class with ':id:' representing
    // the position of the issue number, then add:
    // ->issueNumber(1234) to a mapping.
    $this->issuePattern = 'https://blinkreaction.attask-ondemand.com/task/view?ID=:id:';
  }
  
  /**
   * Provides a connection to the Source Database
   *
   * @param $connection
   * The array key used to define the database connection in settings.php
   *
   * @return DatabaseConnection
   *   The corresponding connection object.
   */
  public function getConnection($connection = 'db_array_key') {
    return Database::getConnection('default', $connection);
  }
}