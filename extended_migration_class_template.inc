<?php
/**
 * @file
 * Short file summary goes here
 * 
 * Longer file description goes here
 * Author: Shawn P. Duncan
 * Date: 6/25/14
 * Time: 2:23 PM
 * 
 *//**
 * Accomplishes what purpose?${CARET}
 *
 * Additional description or info goes here 
 * @todo Complete this docBlock
 * @todo Add this file to the files[] listing in .info
 */
// @todo also add this migration to api array in module.migrate.inc
class extended_migration_class_template extends base_migration_class_template {
  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t(''); //@todo Add a description
    // Instantiate the query object for the source data
    // @todo add Select parameters: 1: The base table for this query, 2:(optional) an alias
    // @todo methods may be chained to the query such as ->isNotNull, ->groupBy, ->orderBy
    // see Dash bookmarks for selectQuery object
    $query = $this->getConnection()->select('table', 'alias')
      ->fields('alias', array('fieldName','fieldName2...'));
    // Instantiate the source object for this migration
    $this->source = new MigrateSourceSQL($query);
    // Instantiate the destination object for this migration
    // @todo Change this MigrateDestination class as needed and/or fill in 'bundle' with correct value
    $this->destination = new MigrateDestinationNode('bundle');
    // Setup the map
    // todo Configure 2nd parameter with Schema API info about source data primary key and delete the following comment block:
    /*
     * An associative array ('fieldname' => specification) that describes the table's database columns. The specification is also
     * an array. The following specification parameters are typical:
     * 'description': A string in non-markup plain text describing this field and its purpose. References to other tables should be
     *         enclosed in curly-brackets. For example, the node table vid field description might contain "Always holds the largest
     *         (most recent) {node_revision}.vid value for this nid."
     * 'type': The generic datatype: 'char', 'varchar', 'text', 'blob', 'int', 'float', 'numeric', or 'serial'. Most types just map
     *         to the according database engine specific datatypes. Use 'serial' for auto incrementing fields. This will expand
     *         to 'INT auto_increment' on MySQL.
     * 'mysql_type', 'pgsql_type', 'sqlite_type', etc.: If you need to use a record type not included in the officially supported
     *         list of types above, you can specify a type for each database backend. In this case, you can leave out the type parameter,
     *         but be advised that your schema will fail to load on backends that do not have a type specified. A possible solution can be
     *         to use the "text" type as a fallback.
     * 'serialize': A boolean indicating whether the field will be stored as a serialized string.
     * 'size': The data size: 'tiny', 'small', 'medium', 'normal', 'big'. This is a hint about the largest value the field will store and
     *         determines which of the database engine specific datatypes will be used (e.g. on MySQL, TINYINT vs. INT vs. BIGINT). 'normal',
     *         the default, selects the base type (e.g. on MySQL, INT, VARCHAR, BLOB, etc.). Not all sizes are available for all data types.
     *         See DatabaseSchema::getFieldTypeMap() for possible combinations.
     * 'default': The field's default value. The PHP type of the value matters: '', '0', and 0 are all different. If you specify '0' as the
     *         default value for a type 'int' field it will not work because '0' is a string containing the character "zero", not an integer.
     * 'not null': If true, no NULL values will be allowed in this database column. Defaults to false.
     * 'length': The maximal length of a type 'char', 'varchar' or 'text' field. Ignored for other field types.
     * 'unsigned': A boolean indicating whether a type 'int', 'float' and 'numeric' only is signed or unsigned. Defaults to FALSE. Ignored for other field types.
     * 'precision', 'scale': For type 'numeric' fields, indicates the precision (total number of significant digits) and scale (decimal digits
     *         right of the decimal point). Both values are mandatory. Ignored for other field types.
     * 'binary': A boolean indicating that MySQL should force 'char', 'varchar' or 'text' fields to use case-sensitive binary collation.
     *         This has no effect on other database types for which case sensitivity is already the default behavior.
     * 'alias': the alias used in the query object above
     *
     * */
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'column_name' => array(
          'schema' => 'value',
          'schema' => 'value',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );
    //@todo Add field mappings
    // Dash shortcut is ;afm
    // @todo Delete the following documentation block after the field migrations are set
    /*
    The following methods can be chained:
        ->description($description): provide a description for the mapping. This will be displayed in the Migrate UI.
        ->defaultValue($value): provide a default value for this field.
        ->separator($delimiter): the source string will be exploded to an array using the specified delimiter.
        ->callbacks($callback1, $callback2, ...): adds functions to be executed in order to prepare the data for that specific field.
          a callback is a function name or array('class', method') such as array($this,'processStuff')
        ->sourceMigration(array($migrationMachineName, ...)): If specified, the source value in the mapping will be looked up in the map tables for any listed migrations and if found, translated to the destination ID from the map table.
        ->dedupe($table, $column): Search for duplicate value in $table and $column. When a duplicate value is found a counter will be appended.
        ->issueGroup($group): Each issue group will generate a tab on the detail page in the UI, for grouping the mappings.
        ->issueNumber($group): If present, used to link to an issue in an external ticketing system.
        ->issuePriority($group): Indicates the priority of an issue (with highlighting for non-OK values).
    */
    $this->addFieldMapping('log')->defaultValue('Imported by extended_migration_class_template');
    
    $this->addUnmigratedDestinations(
      array(
        'simply',
        'list',
        'fields',
      )
    );
  }
  
  /**
   * @param $row
   * stdClass object containing the raw data as provided by the source
   *
   * @return bool
   * TRUE to process this row, FALSE to have the source skip it
   */
  public function prepareRow($row) {
    // Allow parent classes to ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    //@todo row preprocessing
  }
}