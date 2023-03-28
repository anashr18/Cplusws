from dbcat.api import open_catalog, add_postgresql_source
from piicatcher.api import scan_database

# PIICatcher uses a catalog to store its state. 
# The easiest option is to use a sqlite memory database.
# For production usage check, https://tokern.io/docs/data-catalog
catalog = open_catalog(app_dir='/tmp/.config/piicatcher', path=':memory:', secret='my_secret')

with catalog.managed_session:
    # Add a postgresql source
    source = add_postgresql_source(catalog=catalog, name="pg_db", uri="127.0.0.1", username="piiuser",
                                    password="p11secret", database="piidb")
    output = scan_database(catalog=catalog, source=source)

print(output)