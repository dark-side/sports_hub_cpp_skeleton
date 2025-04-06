CREATE TABLE IF NOT EXISTS active_storage_blobs (
    id SERIAL PRIMARY KEY,
    key TEXT NOT NULL,
    filename TEXT NOT NULL,
    content_type TEXT,
    metadata JSONB,
    byte_size BIGINT NOT NULL,
    checksum TEXT NOT NULL,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL
);

CREATE TABLE IF NOT EXISTS active_storage_attachments (
    id SERIAL PRIMARY KEY,
    name TEXT NOT NULL,
    record_type TEXT NOT NULL,
    record_id BIGINT NOT NULL,
    blob_id BIGINT NOT NULL,
    created_at TIMESTAMP NOT NULL,
    CONSTRAINT fk_active_storage_blob FOREIGN KEY (blob_id) REFERENCES active_storage_blobs(id),
    UNIQUE (record_type, record_id, name, blob_id)
);
